#include <iostream>

using std::cin;
using std::cout;
using std::string;

#include <memory>
using std::make_shared;

class Page{
    private:
    
    public:
        
        void link(){
            cout << "there is none" << "\n";
        };
        auto as_string(){
            
        };

};

int main()
{
    auto homepage = make_shared<Page>("My Home Page");
    cout << "Homepage has no links yet:" << "\n";
    cout << homepage->as_string() << "\n";
    
    return 0;
}