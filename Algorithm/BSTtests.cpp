#include "BST.hpp"
#include <iostream>

bool BSTTests() {
    std::cout << "Starting BST tests.\n\n";

    std::cout << "Creating a new BST and starting basic insertions and traversals.\nInserting 4,3,2,1 and then calling all traversals...";
    BST<int> tree;
    for (int i : {4, 3, 2, 1}) {
        tree.insert(i);
    }

    std::string inorder = tree.inOrderTraversal();
    std::string preorder = tree.preOrderTraversal();
    std::string postorder = tree.postOrderTraversal();
    std::string true_inorder = "1,2,3,4,";
    std::string true_preorder = "4,3,2,1,";
    std::string true_postorder = "1,2,3,4,";

    if (inorder != true_inorder || preorder != true_preorder || postorder != true_postorder) {
        std::cout << "Incorrect!\n";
        std::cout << "Your tree, or your traversal functions, are incorrect. Got the following: \n";
        std::cout << "Inorder: " << inorder << '\n';
        std::cout << "Preorder: " << preorder << '\n';
        std::cout << "Postorder: " << postorder << '\n';
        std::cout << "Should have gotten: \n";
        std::cout << "Inorder: " << true_inorder << '\n';
        std::cout << "Preorder: " << true_preorder << '\n';
        std::cout << "Postorder: " << true_postorder << '\n';
        return false;
    }
    std::cout << " OK!\n";

    std::cout << "Creating a new BST and adding more elements.\nInserting 8,4,2,1,3,6,7,5 and then calling all traversals...";
    BST<int> tree2;
    for (int i : {8, 4, 2, 1, 3, 6, 7, 5}) {
        tree2.insert(i);
    }

    inorder = tree2.inOrderTraversal();
    preorder = tree2.preOrderTraversal();
    postorder = tree2.postOrderTraversal();
    true_inorder = "1,2,3,4,5,6,7,8,";
    true_preorder = "8,4,2,1,3,6,5,7,";
    true_postorder = "1,3,2,5,7,6,4,8,";

    if (inorder != true_inorder || preorder != true_preorder || postorder != true_postorder) {
        std::cout << "Incorrect!\n";
        std::cout << "Your tree, or your traversal functions, are incorrect. Got the following: \n";
        std::cout << "Inorder: " << inorder << '\n';
        std::cout << "Preorder: " << preorder << '\n';
        std::cout << "Postorder: " << postorder << '\n';
        std::cout << "Should have gotten: \n";
        std::cout << "Inorder: " << true_inorder << '\n';
        std::cout << "Preorder: " << true_preorder << '\n';
        std::cout << "Postorder: " << true_postorder << '\n';
        return false;
    }
    std::cout << " OK!\n";

    std::cout << "Continuing, by removing 7...";
    tree2.remove(7);

    inorder = tree2.inOrderTraversal();
    preorder = tree2.preOrderTraversal();
    postorder = tree2.postOrderTraversal();
    true_inorder = "1,2,3,4,5,6,8,";
    true_preorder = "8,4,2,1,3,6,5,";
    true_postorder = "1,3,2,5,6,4,8,";

    if (inorder != true_inorder || preorder != true_preorder || postorder != true_postorder) {
        std::cout << "Incorrect!\n";
        std::cout << "Your tree, or your traversal functions, are incorrect. Got the following: \n";
        std::cout << "Inorder: " << inorder << '\n';
        std::cout << "Preorder: " << preorder << '\n';
        std::cout << "Postorder: " << postorder << '\n';
        std::cout << "Should have gotten: \n";
        std::cout << "Inorder: " << true_inorder << '\n';
        std::cout << "Preorder: " << true_preorder << '\n';
        std::cout << "Postorder: " << true_postorder << '\n';
        return false;
    }
    std::cout << " OK!\n";

    std::cout << "Continuing, by removing 1...";
    tree2.remove(1);

    inorder = tree2.inOrderTraversal();
    preorder = tree2.preOrderTraversal();
    postorder = tree2.postOrderTraversal();
    true_inorder = "2,3,4,5,6,8,";
    true_preorder = "8,4,2,3,6,5,";
    true_postorder = "3,2,5,6,4,8,";

    if (inorder != true_inorder || preorder != true_preorder || postorder != true_postorder) {
        std::cout << "Incorrect!\n";
        std::cout << "Your tree, or your traversal functions, are incorrect. Got the following: \n";
        std::cout << "Inorder: " << inorder << '\n';
        std::cout << "Preorder: " << preorder << '\n';
        std::cout << "Postorder: " << postorder << '\n';
        std::cout << "Should have gotten: \n";
        std::cout << "Inorder: " << true_inorder << '\n';
        std::cout << "Preorder: " << true_preorder << '\n';
        std::cout << "Postorder: " << true_postorder << '\n';
        return false;
    }
    std::cout << " OK!\n";

    std::cout << "Continuing, by removing 8...";
    tree2.remove(8);

    inorder = tree2.inOrderTraversal();
    preorder = tree2.preOrderTraversal();
    postorder = tree2.postOrderTraversal();
    true_inorder = "2,3,4,5,6,";
    true_preorder = "4,2,3,6,5,";
    true_postorder = "3,2,5,6,4,";

    if (inorder != true_inorder || preorder != true_preorder || postorder != true_postorder) {
        std::cout << "Incorrect!\n";
        std::cout << "Your tree, or your traversal functions, are incorrect. Got the following: \n";
        std::cout << "Inorder: " << inorder << '\n';
        std::cout << "Preorder: " << preorder << '\n';
        std::cout << "Postorder: " << postorder << '\n';
        std::cout << "Should have gotten: \n";
        std::cout << "Inorder: " << true_inorder << '\n';
        std::cout << "Preorder: " << true_preorder << '\n';
        std::cout << "Postorder: " << true_postorder << '\n';
        return false;
    }
    std::cout << " OK!\n";

    std::cout << "Continuing, by removing 4...";
    tree2.remove(4);

    inorder = tree2.inOrderTraversal();
    preorder = tree2.preOrderTraversal();
    postorder = tree2.postOrderTraversal();
    true_inorder = "2,3,5,6,";
    true_preorder = "5,2,3,6,";
    true_postorder = "3,2,6,5,";

    if (inorder != true_inorder || preorder != true_preorder || postorder != true_postorder) {
        std::cout << "Incorrect!\n";
        std::cout << "Your tree, or your traversal functions, are incorrect. Got the following: \n";
        std::cout << "Inorder: " << inorder << '\n';
        std::cout << "Preorder: " << preorder << '\n';
        std::cout << "Postorder: " << postorder << '\n';
        std::cout << "Should have gotten: \n";
        std::cout << "Inorder: " << true_inorder << '\n';
        std::cout << "Preorder: " << true_preorder << '\n';
        std::cout << "Postorder: " << true_postorder << '\n';
        return false;
    }
    std::cout << " OK!\n";

    std::cout << "All BST tests OK!\n";
    return true;
}



int main(int argc, char const *argv[])
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	if (BSTTests())
		return 0;
	return 1;
}