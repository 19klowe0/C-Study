using namespace std;
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>


//swaps two variables of the same type
template<typename T>
void swapnum(T i, T j) {
    T temp = i;
    i = j;
    j = temp;
}

//finds the max length of Substring Without Repeating Characters
//used this sets 
int lengthOfLongestSubstring(string s) {

    if (s.length() == 0) {
        return 0;
    }
    int i = 0;
    int j = 0;
    int maxLength = 0;

    set <char> s1;

    for (i = 0; i < s.length(); i++) {
        char c = s[i];
        //checking if c is there, if not erase till we erase c 
        while (s1.find(c) != s1.end())
        {
            s1.erase(s[j]);
            j++;
        }

        s1.insert(c);
        //find max length 
        maxLength = max(maxLength, i - j + 1);
    }
    return maxLength;
}

//study in vectors (like java arrays) 
//Given an integer array nums of length n and an integer target, 
//find three integers in nums such that the sum is closest to target.

//can be done with 2 points one points to the end and one points to the beginnig
//add them all together and find the difference between that and the target 
int threeSumClosest(vector<int>& nums, int target) {
    int i, j, k;
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int diff = INT_MAX;
    int d;
    int sum;
    for (i = 0; i < n; i++)
    {
        j = i + 1;
        k = n - 1;
        while (j < k)
        {
            d = abs(target - (nums[i] + nums[j] + nums[k]));
            if (diff >= d)
            {
                diff = d;
                sum = nums[i] + nums[j] + nums[k];
            }
            if ((nums[i] + nums[j] + nums[k]) <= target)
            {
                j = j + 1;
            }
            else {
                k = k - 1;
            }
        }
    }
    return sum;
}

int main()
{
   /* int a = 3;
    int b = 4;

    swapnum(a, b);
    cout << "A is "<<a<<" b is "<<b << endl;

   
    string s = "hbbbbbbn";
    int temp = lengthOfLongestSubstring(s);

    cout << "the max length of longest Substring without repeating characters of "<<s<<" is "<<temp ;*/

    //vector declaration
    //n = size, 10 is all the values at the position
    //vector<int> vect(n, 10);
    
    //can be initialized like an array
    vector<int> nums{ -1, 2, 1, -4 };

    int target = 1;
    int sum = threeSumClosest(nums, target);
    



    cout << "the closest sum to the target it " << sum << endl;

}
