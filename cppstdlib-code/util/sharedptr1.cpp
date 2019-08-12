#include <iostream>
#include <string>
#include <vector>
#include <memory>
using namespace std;

int main()
{
    // two shared pointers representing two persons by their name
    shared_ptr<string> pNico(new string("nico"));
    shared_ptr<string> pJutta(new string("jutta"));

    // capitalize person names
    (*pNico)[0] = 'N';
    pJutta->replace(0,1,"J");
    
    // put them multiple times in a container
    vector<shared_ptr<string>> whoMadeCoffee;
    whoMadeCoffee.push_back(pJutta);
    whoMadeCoffee.push_back(pJutta);
    whoMadeCoffee.push_back(pNico);
    whoMadeCoffee.push_back(pJutta);
    whoMadeCoffee.push_back(pNico);

    // print all elements
    for (auto ptr : whoMadeCoffee) {
        cout << *ptr << "  "; // Jutta  Jutta  Nico  Jutta  Nico
    }
    cout << endl;

    // overwrite a name again
    *pNico = "Nicolai";

    // print all elements again
    for (auto ptr : whoMadeCoffee) {
        cout << *ptr << "  "; // Jutta  Jutta  Nicolai  Jutta  Nicolai
    }
    cout << endl;
    
    // print some internal data
	// use_count()返回智能指针所指对象的,当前拥有者数量(pJutta和vector内的3份拷贝)
    cout << "use_count: " << whoMadeCoffee[0].use_count() << endl; // use_count: 4
}
