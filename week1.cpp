#include <iostream>
#include <vector>
using namespace std;


int fact(int n)
{
    if (n == 0) return 1;
    return n * fact(n - 1);
}
int fib(int n)
{
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fib(n - 1) + fib(n - 2);
}
int gcd(int a, int b)
{
    if (b == 0) return a;
    return gcd(b, a % b);
}




void permutationRepeat(vector<int>& nums, vector<int>& current)
{
    if (nums.empty()) return;

    if (current.size() == nums.size()) 
    {
        for (int num : current)
        {
            cout << num << " ";
        }
        cout << '\n';
        return;
    }

    for (int i = 0; i < nums.size(); i++)
    {
        current.push_back(nums[i]);
        permutationRepeat(nums, current);
        current.pop_back();
        
    }
}
void permutationNoRepeat(vector<int>& nums, vector<int>& current, vector<bool>& used)
{ 
    if (nums.empty()) return;

    if (current.size() == nums.size())
    {
        for (int num : current)
        {
            cout << num << " ";
        }
        cout << '\n';
        return;
    }

    for (int i = 0; i < nums.size(); i++)
    {
        if (used[i]) continue;

        used[i] = true;
        current.push_back(nums[i]);
       
        permutationNoRepeat(nums, current, used);

        current.pop_back();
        used[i] = false;
    }
}

void variationRepeat(vector<int>& nums, vector<int>& curr, int k)
{
    if (curr.size() == k)
    {
        for (int num : curr)
        {
            cout << num << " ";
        }
        cout << endl;
        return;
    }


    for (int i = 0; i < nums.size(); i++)
    {
        curr.push_back(nums[i]);
        variationRepeat(nums, curr, k);
        curr.pop_back();
    }
}
void variationNoRepeat(vector<int>& nums, vector<int>& curr, vector<bool>& used, int k)
{
    if (curr.size() == k)
    {
        for (int num : curr)
        {
            cout << num << " ";
        }
        cout << endl;
        return;
    }


    for (int i = 0; i < nums.size(); i++)
    {
        if (used[i]) continue;

        used[i] = true;
        curr.push_back(nums[i]);

        variationNoRepeat(nums, curr, used, k);

        curr.pop_back();
        used[i] = false;
    }
}

void combinationRepeat(vector<int>& nums, vector<int>& curr, int start, int k)
{
    if (curr.size() == k)
    {
        for (int num : curr)
            cout << num << " ";
        cout << endl;
        return;
    }


    for (int i = start; i < nums.size(); i++)
    {
        curr.push_back(nums[i]);
        combinationRepeat(nums, curr, i, k);
        curr.pop_back();
    }
}
void combinationNoRepeat(vector<int>& nums, vector<int>& curr, int start, int k)
{
    if (curr.size() == k)
    {
        for (int num : curr)
            cout << num << " ";
        cout << endl;
        return;
    }


    for (int i = start; i < nums.size(); i++)
    {
        curr.push_back(nums[i]);
        combinationNoRepeat(nums, curr, i + 1, k);
        curr.pop_back();
    }
}



void printSum(const int* number, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << number[i];
        if (i + 1 < size) cout << " + ";
        
    }
    cout << endl;
}
void divideNumber(int n, int* rest, int pos)
{
    if (n == 0)
        printSum(rest, pos);

    else
    {
        for (int i = n; i > 0; i--)
        {
            rest[pos] = i;
            if (pos == 0 || rest[pos] <= rest[pos - 1]) divideNumber(n - i, rest, pos + 1);
        }
    }
}
void sumOfNumber(int n)
{
    int* rest = new int[n];
    divideNumber(n, rest, 0);
    delete[] rest;

}





int main()
{
    vector<int> nums = { 1,2,3 };
    vector<int> current;
    vector<bool>used(nums.size(), false);

    
  
   /* permutationRepeat(nums, current);
    cout << endl;
    permutationNoRepeat(nums, current, used);
    cout << endl;*/


    /*variationRepeat(nums, current, 2);
    cout << endl;
    variationNoRepeat(nums, current, used, 2);
    cout << endl;*/

    /*combinationRepeat(nums, current, 0, 2);
    cout << endl;
    combinationNoRepeat(nums, current, 0, 2);*/

    //sumOfNumber(5);


    

}
