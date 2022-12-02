#include <iostream>

using std::cin;
using std::cout;
using std::string;

#include <vector>
#include <memory>
using std::make_shared;
using std::shared_ptr;
using std::vector;

#include <stdio.h>
#include <stdlib.h>





class Page{
    private:
        int linkamount;
        string name;
        vector<shared_ptr<Page>> links;
        shared_ptr<Page> next{nullptr};

    public:
        
        // Page constructor
        Page(string n)
        {
            linkamount = 0;
            links.resize(1);
            name = n;
        }

        void link(){
            cout << "there is none" << "\n";
        };
        auto as_string(){
            return name;
        };

        void add_link(shared_ptr<Page> p)
        {
            // allocating new link into a point
            links[linkamount] = p;
            linkamount++;
            links.resize(linkamount+1);
        }

        shared_ptr<Page> click(int i)
        {
            return links[i];
        }

        shared_ptr<Page> random_click()
        {
            if(linkamount == 0)
            {
                throw("ERROR: no links. Need to program this CASE. \n");
            }
            // providing a seed value
            srand(time(NULL));

            // get a random number within the given number of links
            int random = rand() % linkamount;
            
            return click(random);
        }

};

int main()
{
    auto home = Page("My home page");
    auto homepage = make_shared<Page>("My Home Page");
    cout << "Homepage has no links yet:" << "\n";
    cout << homepage->as_string() << "\n";


    auto utexas = make_shared<Page>("University Home Page");
    homepage->add_link(utexas);
    auto searchpage = make_shared<Page>("google");
    homepage->add_link(searchpage);
    cout << homepage->as_string() << "\n";


    auto newpage = homepage->random_click();
    cout << "To: " << newpage->as_string() << "\n";
    
    return 0;
}