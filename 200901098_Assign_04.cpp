#include <iostream>
#include <string>
#include <thread>
#include <atomic>
using namespace std;
  atomic<bool> input_done(false);
  string input_str;

void input_thread_func()
{
    cout << "Enter a string: ";
    cin >> input_str;
    input_done = true;
}

void reverse_thread_func()
{
    while (!input_done); // wait for input thread to finish
    string reversed_str;
    for (int i = input_str.size() - 1; i >= 0; i--)
        reversed_str += input_str[i];
    cout << "Reversed string: " << reversed_str << endl;
}

void capital_thread_func()
{
    while (!input_done); // wait for input thread to finish
    string capitalized_str;
    for (char c : input_str)
        capitalized_str += (c >= 'a' && c <= 'z') ? c - 'a' + 'A' : c;
    cout << "Capitalized string: " << capitalized_str << endl;
}

void shift_thread_func()
{
    while (!input_done); // wait for input thread to finish
    string shifted_str;
    for (char c : input_str)
        shifted_str += (c >= 'a' && c <= 'z') ? c + 2 > 'z' ? c + 2 - 'z' + 'a' - 1 : c + 2 : c;
    cout << "Shifted string: " << shifted_str << endl;
}

int main()
{
    thread input_thread(input_thread_func);
    thread reverse_thread(reverse_thread_func);
    thread capital_thread(capital_thread_func);
    thread shift_thread(shift_thread_func);

    input_thread.join();
    reverse_thread.join();
    capital_thread.join();
    shift_thread.join();

    return 0;
}



