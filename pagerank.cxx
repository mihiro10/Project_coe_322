#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <stdio.h>
#include <stdlib.h>

using std::cin;
using std::cout;
using std::string;


using std::make_shared;
using std::shared_ptr;
using std::vector;






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


class Web
{
    private:
        int netsize;
        vector<shared_ptr<Page>> pages;




    public:
        Web(int size)
        {
            netsize = size;
            pages.resize(netsize);
            for(int i = 0; i < size; i++)
            {
                auto str = std::to_string(i);
                auto name = "Page " + str;
                
                pages[i] = make_shared<Page>(name);
            }
        }

        void create_random_links(int avgLinks)
        {
            int n = avgLinks * netsize;
            for(int i = 0; i < n; i++)
            {
                //Pick page from pages vector at random (page1 = rand page)

                //Pick second page from pages vector at random (page 2 = rand page)

                //Set link from page1 to page2 (page1.addlink(page2))
            }
        }

        void print()
        {
            for(int i = 0; i < netsize; i++)
            {
                cout << pages[i]->as_string() << std::endl;
            }
        }


};



int main()
{
    int netsize = 10;
    Web internet(netsize);

    internet.print();

    
    return 0;
}