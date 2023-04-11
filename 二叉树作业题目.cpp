#include <iostream>
#include <string>
#include <stdio.h>
#include <queue>
#include <math.h>

using namespace std;

const string _PreOrder = "前序遍历: ";
const string _MidOrder = "中序遍历: ";
const string _PostOrder = "后序遍历: ";
const string _SeqOrder = "层序遍历: ";
const string _LeafNode = "叶子节点: ";
const string _Depth = "二叉树深度: ";

class TreeNode {
private:
	TreeNode *left; // 左孩子
	TreeNode *right; // 右孩子
	char val; // 节点存放的值

		// 求出叶子节点
	int LeafNode(TreeNode* root)
	{
		if (root == nullptr)
		{
			return 0;
		}
		if (!root->left && !root->right)
		{
			return 1;
		}
		return LeafNode(root->left) + LeafNode(root->right);
	}

	// 二叉树的深度
	int Depth(TreeNode* root)
	{
		if (root == nullptr)
		{
			return 0;
		}
		return 1 + max(Depth(root->left), Depth(root->right));
	}

	// 层序遍历
	void SeqOrder(TreeNode* root)
	{
		// 定义队列
		queue<TreeNode*> queue;
		// 头部放入一个节点
		queue.push(root);
		while (!queue.empty())
		{
			int N = queue.size();
			for (int i = 0; i < N; i++)
			{
				TreeNode* cur = queue.front();
				queue.pop();
				printf("%c ", cur->val);
				// 遍历完成之后加入节点到队列
				if (cur->left != nullptr)
				{
					queue.push(cur->left);
				}
				if (cur->right != nullptr)
				{
					queue.push(cur->right);
				}
			}
		}
	}

	// 前序遍历
	void PreOrder(TreeNode* root)
	{
		if (root == nullptr)
		{
			return;
		}
		printf("%c ", root->val);
		PreOrder(root->left);
		PreOrder(root->right);
	}

	// 中序遍历
	void MidOrder(TreeNode* root)
	{
		if (root == nullptr)
		{
			return;
		}
		PreOrder(root->left);
		printf("%c ", root->val);
		PreOrder(root->right);
	}

	// 后序遍历
	void PostOrder(TreeNode* root)
	{
		if (root == nullptr)
		{
			return;
		}
		PreOrder(root->left);
		PreOrder(root->right);
		printf("%c ", root->val);
	}
public:

	TreeNode()
	{
		this->val = 'A';
		this->left = nullptr;
		this->right = nullptr;
	}

	// 构造二叉树
	TreeNode* CreateTree()
	{
		TreeNode* A = new TreeNode();
		TreeNode* B = new TreeNode();
		TreeNode* C = new TreeNode();
		TreeNode* D = new TreeNode();
		TreeNode* E = new TreeNode();
		TreeNode* F = new TreeNode();
		TreeNode* G = new TreeNode();
		A->val = 'A';
		B->val = 'B';
		C->val = 'C';
		D->val = 'D';
		E->val = 'E';
		F->val = 'F';
		G->val = 'G';
		A->left = B;
		A->right = C;
		B->left = D;
		C->left = E;
		C->right = F;
		D->left = nullptr;
		D->right = G;
		E->left = nullptr;
		E->right = nullptr;
		F->left = nullptr;
		F->right = nullptr;
		return A;
	}

	void EventCount(TreeNode* root, const string way)
	{
		cout << way;
		int res = 0;
		if (way == _Depth)
		{
			res = Depth(root);
		}
		if (way == _LeafNode)
		{
			res = LeafNode(root);
		}
		printf("%d \n", res);
	}

	void EventOrder(TreeNode* root, const string way)
	{
		cout << way;
		if (way == _PreOrder)
		{
			PreOrder(root);
		}
		if (way == _PostOrder)
		{
			PostOrder(root);
		}
		if (way == _MidOrder)
		{
			MidOrder(root);
		}
		if (way == _SeqOrder)
		{
			SeqOrder(root);
		}
		printf("\n");
	}
};

int main()
{
	TreeNode root;
	TreeNode *_root = root.CreateTree();
	root.EventOrder(_root, _PreOrder);
	root.EventOrder(_root, _MidOrder);
	root.EventOrder(_root, _PostOrder);
	root.EventOrder(_root, _SeqOrder);
	root.EventCount(_root, _LeafNode);
	root.EventCount(_root, _Depth);
}
