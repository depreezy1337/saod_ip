#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node* left;
    Node* right;
};
Node* createNode(int data)
{
    Node* newNode = new Node();
    if (newNode == nullptr)
    {
        cout << "Ошибка: Не удалось выделить память для нового узла." << endl;
        exit(1);
    }
    newNode->data = data;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}
Node* insertNode(Node* root, int data)
{
    if (root == nullptr)
    {
        root = createNode(data);
        return root;
    }
    if (data <= root->data)
    {
        root->left = insertNode(root->left, data);
    }
    else
    {
        root->right = insertNode(root->right, data);
    }
    return root;
}
void preorderTraversal(Node* root)
{
    static int counter = 1;
    if (root == nullptr)
    {
        return;
    }
    cout << "Узел " << counter++ << ": " << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void inorderTraversal(Node* root)
{
    static int counter = 1;
    if (root == nullptr)
    {
        return;
    }
    inorderTraversal(root->left);
    cout << "Узел " << counter++ << ": " << root->data << " ";
    inorderTraversal(root->right);
}
void postorderTraversal(Node* root)
{
    static int counter = 1;
    if (root == nullptr)
    {
        return;
    }
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << "Узел " << counter++ << ": " << root->data << " ";
}
int getSize(Node* root)
{
    if (root == nullptr)
    {
        return 0;
    }
    return 1 + getSize(root->left) + getSize(root->right);
}
int getSum(Node* root)
{
    if (root == nullptr)
    {
        return 0;
    }
    return root->data + getSum(root->left) + getSum(root->right);
}
int getHeight(Node* root)
{
    if (root == nullptr)
    {
        return -1;
    }
    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);
    return 1 + max(leftHeight, rightHeight);
}
float getAverageHeight(Node* root)
{
    int size = getSize(root);
    int sumHeight = getHeight(root) * size;
    return static_cast<float>(sumHeight) / size;
}
int main()
{
    setlocale(LC_ALL, "RUS");
    Node* root = nullptr;
    int data[] = { 5, 10, 6, 9, 8, 7 };
    int dataSize = sizeof(data) / sizeof(data[0]);
    for (int i = 0; i < dataSize; i++)
    {
        root = insertNode(root, data[i]);
    }
    cout << "Прямой обход (сверху вниз): ";
    preorderTraversal(root);
    cout << endl;
    cout << "Центрированный обход (слева направо): ";
    inorderTraversal(root);
    cout << endl;
    cout << "Обратный обход (снизу вверх): ";
    postorderTraversal(root);
    cout << endl;
    int size = getSize(root);
    int sum = getSum(root);
    int height = getHeight(root);
    float averageHeight = getAverageHeight(root);
    cout << "Размер дерева: " << size << endl;
    cout << "Контрольная сумма: " << sum << endl;
    cout << "Высота дерева: " << height << endl;
    cout << "Средняя высота дерева: " << averageHeight << endl;
    return 0;
}