#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    if (argc > 2)
    {
        cerr << "Usage: " << argv[0] << " <number>" << endl;
        return 1;
    }

    string x = argv[1];
    cout << "Hello world " << x << endl;
    return 0;
}