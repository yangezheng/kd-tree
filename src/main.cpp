#include "kd-tree.h"
#include "kd-search.h"
#include "helper.h"

int main()
{
    // creates kd-tree from file
    auto kdt = createKDTreeFromFile("../data/points.csv", 3);

    // print it to terminal
    kdt->printKDT();
            

    // print the minumun vector in each dimension
    auto x = kdt->findMin(0);
    auto y = kdt->findMin(1);
    auto z = kdt->findMin(2);
    std::cout << "min Point on dimension 0 is: [" << x->vector[0] << "," << x->vector[1] << "," << x->vector[2] << "]"
              << "\n";
    std::cout << "min Point on dimension 1 is: [" << y->vector[0] << "," << y->vector[1] << "," << y->vector[2] << "]"
              << "\n";
    std::cout << "min Point on dimension 1 is: [" << z->vector[0] << "," << z->vector[1] << "," << z->vector[2] << "]"
              << "\n";
    // delete a vector to demonstrate
    std::cout << "now we demonstrate the delete node function, type in a 3d-vector to delete: \n";
    std::cout << "type the first cordinate: \n";
    int first;
    std::cin >> first;

    std::cout << "now type the second cordinate: \n";
    int second;
    std::cin >> second;

    std::cout << "now type the thrid cordinate: \n";
    int third;
    std::cin >> third;
    try
    {
        kdt->deleteNode({first, second, third});
    }
    catch (
        const char *msg)
    {
        std::cout << msg << "\n";
        return 1;
    }

    // print the tree again after the deletion
    kdt->printKDT();
}