
/* Reference: http://cslibrary.stanford.edu/110/BinaryTrees.pdf */


/* In BST, minimum value is in the left most node. */
int minValue(struct node *head)
{
    if (!head) return 0;
    
    while (head->next) head = head->next;
    
    return head->data;
}

/* *
 * Given a BST and a sum, return true if the tree has a root-to-leaf path such that adding
 * up all the values along the path equals the given sum. Return false if no such path can
 * be found.
 */
bool hasPathSum(struct node *head, int sum)
{
    if (!head) return sum == 0;
    else {
        int subSum = sum - head->data;
        return hasPathSum(head->left, subSum) || hasPathSum(head->right, subSum);
    }
}

/* Change a tree so that the roles of the left and right pointers are swapped at every node. */
void mirrorTree(struct node *head)
{
    if (!head) return;
    else {
        mirrorTree(head->left);
        mirrorTree(head->right);
        struct node *tmp = head->left;
        head->left = head->right;
        head->right = tmp;
    }
}
