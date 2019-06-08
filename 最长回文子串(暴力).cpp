//
//  main.cpp
//  最长回文子串（暴力）
//
//  Created by 唧唧歪歪 on 15/4/30.
//  Copyright (c) 2015年 唧唧歪歪. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

//判断字符串是否为回文串；
bool Reverse(string str)
{
        char * ch = new char [str.length()];
        int i;
        
        for (i = (int)str.length(); i > 0; i--) {
                ch[str.length()-i] = str[i-1];
        }
    
        string reverse(ch);

        if (str == reverse) {
                delete ch;
                return true;
        } else {
                delete ch;
                return false;
        }
}

//利用暴力法遍历所有的字符的最大回文串；
string longestPalindrome(string s) {
        int i,j;//表示临时变量；
        int max_length = 0;//表示长度；
        string  ss;
        for (i=0; i<s.length(); i++) {
                string ttt;
                for (j = i; j < s.length(); j++) {
                        ttt += s[j];
            
                        if (Reverse(ttt) == true) {
                                if (ttt.length() > max_length) {
                                        max_length = (int)ttt.length();
                                        ss = ttt;
                                }
                        }
                }
        }
        return ss;
}

//主函数；
int main() {
    cout << "请输入字符串:" << endl;
    string str;
    cin >> str;
    string sss = longestPalindrome(str);
    cout << "最长回文子串为:" << sss << endl;
}
