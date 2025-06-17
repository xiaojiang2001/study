#include <bits/stdc++.h>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};


#define BOOK 0
#define SYSTEM 1


// C++书籍版本
#if BOOK
// 序列化二叉树
void Encoder(TreeNode* root, ostream& stream)
{
    // 空节点
    if(root == nullptr) {
        stream << "$,";
        return;
    }

    // 非空节点
    stream << root->val << ",";     // 中
    Encoder(root->left, stream);    // 左
    Encoder(root->right, stream);   // 右
}



// 反序列化二叉树
bool readStream(istream& stream, int *number)
{
    // 检查输入流和指针的有效性
    if (!stream || number == nullptr) {
        return false;
    }
    
    // 尝试读取数字
    if (stream >> *number) {
        return true;
    }
    
    return false;
}

void Decoder(TreeNode** root, istream& stream)
{
    int number;
    if(readStream(stream, &number))
    {
        *root = new TreeNode(number);
        (*root)->left = nullptr;
        (*root)->right = nullptr;

        Decoder(&((*root)->left), stream);
        Decoder(&((*root)->right), stream);
    }
}
#endif


// C++系统
#if SYSTEM
char *res;
void traversal(TreeNode* root)
{
    if(root == nullptr) {
        // char* temp = (char*)malloc(sizeof("$,"));
        strcat(res, "$,");
        return;
    }

    char num[4];
    sprintf(num, "%d,", root->val);
    strcat(res, num);
    traversal(root->left);
    traversal(root->right);
}

char* Serialize(TreeNode *root) {   
    res =  new char[4096];
    traversal(root);
    return res;
}

TreeNode* Deserialize(char *str) 
{

}
#endif



int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(6);

    #if BOOK
    std::ofstream fileStream("tree.txt");
    if(fileStream.is_open()) {
        Encoder(root, fileStream);
        fileStream.close();
    }
    #endif


    #if SYSTEM
    char *res = Serialize(root);
    printf("%s\n",res);
    #endif


    return 0;
}