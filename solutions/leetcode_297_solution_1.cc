#include "headers.h"

/*
序列化是将一个数据结构或者对象转换为连续的比特位的操作，进而可以将转换后的数据存储在一个文件或者内存中，
同时也可以通过网络传输到另一个计算机环境，采取相反方式重构得到原数据。

请设计一个算法来实现二叉树的序列化与反序列化。这里不限定你的序列 / 反序列化算法执行逻辑，
你只需要保证一个二叉树可以被序列化为一个字符串并且将这个字符串反序列化为原始的树结构。

提示: 输入输出格式与 LeetCode 目前使用的方式一致，详情请参阅 LeetCode 序列化二叉树的格式。
你并非必须采取这种方式，你也可以采用其他的方法解决这个问题。

示例 1：
输入：root = [1,2,3,null,null,4,5]
输出：[1,2,3,null,null,4,5]

示例 2：
输入：root = []
输出：[]

示例 3：
输入：root = [1]
输出：[1]

示例 4：
输入：root = [1,2]
输出：[1,2]

*/

class Codec {
public:
    void serialize(TreeNode* root, string& serialized_str) {
        if (!root) {
            serialized_str.push_back('#');
            serialized_str.push_back(',');
            return; 
        }
        serialized_str += to_string(root->val);
        serialized_str.push_back(',');
        serialize(root->left, serialized_str);
        serialize(root->right, serialized_str);
        return;
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string str("");
        serialize(root, str);
        return str;
    }


    vector<string> split(const string& str, const string& delim) {  
      vector<string> res;  
      if("" == str) return res;  
      //先将要切割的字符串从string类型转换为char*类型  
      char * strs = new char[str.length() + 1] ; //不要忘了  
      strcpy(strs, str.c_str());   
    
      char * d = new char[delim.length() + 1];  
      strcpy(d, delim.c_str());  
    
      char *p = strtok(strs, d);  
      while(p) {  
        string s = p; //分割得到的字符串转换为string类型  
        res.push_back(s); //存入结果数组  
        p = strtok(NULL, d);  
      }  
    
      return res;  
    }
    
    TreeNode* deserialize(list<string>& nodes) {
        if (nodes.empty()) {
            return nullptr;
        }

        string first = nodes.front();
        nodes.pop_front();
        if (first == "#") {
            return nullptr;
        }
        TreeNode* root = new TreeNode(stoi(first));
        root->left = deserialize(nodes);
        root->right = deserialize(nodes);
        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        list<string> nodes;
        for (auto s : split(data, ",")) {
            nodes.push_back(s);
        }
        return deserialize(nodes);
    }
};