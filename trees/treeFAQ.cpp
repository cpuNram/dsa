

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
