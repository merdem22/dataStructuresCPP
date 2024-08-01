#include <iostream>
#include "binary_search_tree.cpp"

void test_insert(binary_search_tree &bst)
{
    bst.insert(bst, new binary_search_tree::node(10, 100));
    bst.insert(bst, new binary_search_tree::node(5, 50));
    bst.insert(bst, new binary_search_tree::node(20, 200));
    bst.insert(bst, new binary_search_tree::node(15, 150));
    bst.insert(bst, new binary_search_tree::node(30, 300));

    // Tree structure:
    //        10
    //       /  \
    //      5   20
    //         /  \
    //        15  30
}

void test_search(binary_search_tree &bst)
{
    auto result = bst.search(15, bst.root);
    std::cout << "Search for key 15: " << (result != nullptr ? "Found" : "Not Found") << std::endl;

    result = bst.search(25, bst.root);
    std::cout << "Search for key 25: " << (result != nullptr ? "Found" : "Not Found") << std::endl;
}

void test_min_max(binary_search_tree &bst)
{
    auto min_node = bst.min(bst.root);
    auto max_node = bst.max(bst.root);

    std::cout << "Min key: " << (min_node ? min_node->key : -1) << std::endl;
    std::cout << "Max key: " << (max_node ? max_node->key : -1) << std::endl;
}

void test_successor_predecessor(binary_search_tree &bst)
{
    auto node_15 = bst.search(15, bst.root);
    auto successor_15 = bst.successor(node_15);
    std::cout << "Successor of 15: " << (successor_15 ? successor_15->key : -1) << std::endl;

    auto node_20 = bst.search(20, bst.root);
    auto predecessor_20 = bst.predecessor(node_20);
    std::cout << "Predecessor of 20: " << (predecessor_20 ? predecessor_20->key : -1) << std::endl;
}

void test_delete(binary_search_tree &bst)
{
    auto node_10 = bst.search(10, bst.root);
    bst.deleteNode(bst, node_10);

    auto result = bst.search(10, bst.root);
    std::cout << "Search for key 10 after deletion: " << (result != nullptr ? "Found" : "Not Found") << std::endl;
}

int main()
{
    binary_search_tree bst;

    // Test insertion
    test_insert(bst);

    // Test search
    test_search(bst);

    // Test min and max
    test_min_max(bst);

    // Test successor and predecessor
    test_successor_predecessor(bst);

    // Test deletion
    test_delete(bst);

    return 0;
}
