#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>

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
        int globalID;

    public:
        
        // Page constructor
        Page(string n)
        {
            linkamount = 0;
            links.resize(1);
            name = n;
            
        }

        Page(string n, int id)
        {
            linkamount = 0;
            links.resize(1);
            name = n;
            globalID = id;

            
        }

        auto global_ID()
        {
            return globalID;
        }

        int link_amount()
        {
            return linkamount;
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
                
                pages[i] = make_shared<Page>(name, i);
            }
        }

        auto all_pages()
        {
            return pages;
        }

        auto number_of_pages()
        {
            return netsize;
        }

        void create_random_links(int avgLinks)
        {
            

            int n = avgLinks * netsize;
            srand(time(NULL));

            // get a random number within the given number of links
            int randomX, randomY;
            for(int i = 0; i < n; i++)
            {
                //Pick page from pages vector at random (page1 = rand page)
                randomX = rand() % netsize;

                //Pick second page from pages vector at random (page 2 = rand page)
                randomY = rand() % netsize;
                while (randomX == randomY){
                    randomY = rand() % netsize;
                }
                //Set link from page1 to page2 (page1.addlink(page2))
                auto pageX = pages[randomX];
                auto pageY = pages[randomY];
                pageX->add_link(pageY);
            }
        }

        auto random_walk(shared_ptr<Page> startingPage, int length)
        {
            //Current page set to starting page to track which page we started at
            shared_ptr<Page> currentPage = startingPage;
            for(int i = 0; i < length; i++)
            {
                if(currentPage->link_amount() == 0)
                {
                    return currentPage;
                }
                currentPage = currentPage->random_click();
            }
            return currentPage;
        }

        auto getPage(int n)
        {
            return pages[n];
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
    int netsize = 20;
    Web internet(netsize);

    int avglinks = 5;
    
    internet.create_random_links(avglinks);
    
    srand(time(NULL));

    vector<int> landing_counts(internet.number_of_pages(),0);
    for ( auto page : internet.all_pages() ) 
    {
        for (int iwalk=0; iwalk<5; iwalk++) {

	    int randomSteps = rand() % 2*avglinks;
            auto endpage = internet.random_walk(page, randomSteps);

            //FIGURE THIS SHIT OUT
            // PLEASE
            // NOW
            // Need to find out what index endpage is in the internet.all_pages() vector
            landing_counts.at(endpage->global_ID())++;
        }
    }

  for (int i = 0; i < landing_counts.size(); i++){

	cout << "Page " << i << " Landed on: "  << landing_counts.at(i) << ", Total Links: " << internet.getPage(i)->link_amount() <<  std::endl;

  }
    
    return 0;
}
