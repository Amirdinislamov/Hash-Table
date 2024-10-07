#include "Table.h"
#include "Mem.h"
#include "test.h"

int main()
{
    Test_table table_1(10);
    auto s = std::chrono::high_resolution_clock::now();
    table_1.test_1_contest(1000);
    table_1.test_2_contest();
    table_1.test_3_contest();
    //table_1.test_4_contest();
    table_1.test_5_contest();
    table_1.test_6_contest();
    auto finish = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double, std::milli> elapsed = finish - s;
    std::cout << "Time: " << elapsed.count() << endl;
    return 1;
}



