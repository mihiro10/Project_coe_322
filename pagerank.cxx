#include <iostream>

using std::cin;
using std::cout;
using std::string;

#include <memory>
using std::make_shared;
using std::shared_ptr;

class Page{
    private:
        string name;
        shared_ptr<Page> next{nullptr};

    public:
        
        Page(string n)
        {
            name = n;
        }

        void link(){
            cout << "there is none" << "\n";
        };
        auto as_string(){
            return name;
        };

};

int main()
{
    auto homepage = make_shared<Page>("My Home Page");
    cout << "Homepage has no links yet:" << "\n";
    cout << homepage->as_string() << "\n";
    
    return 0;
}