#include <iostream>  
#include <vector>  
#include <iomanip> 
#include <algorithm> 
using namespace std; 

int main() {  
    int n;  
    cin >> n; // 输入评委人数  
    vector<int> scores(n); // 存储各评委的评分  

    for (int i = 0; i < n; ++i) {  
        cin >> scores[i]; // 输入每位评委的评分  
    }  

    // 从第三位评委开始输出  
    for (int i = 2; i < n; ++i) {  
        // 当前前 i + 1 名评委的评分  
        vector<int> current_scores(scores.begin(), scores.begin() + i + 1);  
        // 找到最大分和最小分  
        int max_score = *max_element(current_scores.begin(), current_scores.end());  
        int min_score = *min_element(current_scores.begin(), current_scores.end());  
        
        // 移除一个最大分和一个最小分  
        current_scores.erase(remove(current_scores.begin(), current_scores.end(), max_score), current_scores.end());  
        current_scores.erase(remove(current_scores.begin(), current_scores.end(), min_score), current_scores.end());  
        
        // 计算剩余分数的平均值  
        double average_score = 0.0;  
        for (int score : current_scores) {  
            average_score += score;  
        }  
        average_score /= current_scores.size();  
        
        // 输出保留两位小数的平均分  
        cout << fixed << setprecision(2) << average_score << endl;  
    }  

    return 0;  
}