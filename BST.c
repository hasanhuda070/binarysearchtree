/*
large data set of an area with income and number of people having that income. 
You want to create an efficient search system using Binary Search Tree (BST) to search an income and related count.

Input to be read from in.txt file

Output: display the result in console

Tasks:
Create a binary search tree based on the income as the key. 
However, you should also store the corresponding count within the BST node.
Print the data in the tree in the in-order traversal 
to see the keys are in sorted order. 
Print them like comma separated tuple (income, count), (income, count), ….                       
Write a function that prints all the incomes with odd number of people count.
Write a function to find the total number of people 
having the highest income from your tree.
    
*/

//Showad Huda
//Lab Quiz 2 - COP3502C
//4/23/21

//Include pre-processor directives
#include <stdio.h>
#include <stdlib.h>

//Tree stucture node function for BST
struct tree_node{
	//Defining variables
	int count;
	int income;
	//Pointer directions
	struct tree_node* left;
	struct tree_node* right;
};

//Place input results in order ascending
void inorder(struct tree_node *root,FILE *fout){
	if(root == NULL)
		return;
	inorder(root -> left, fout);
	fprintf(fout,"(%d, %d),",root -> income,root -> count);
	printf("(%d, %d),",root -> income, root -> count);
	inorder(root -> right, fout);
}

//Tree structure provided and worked on
struct tree_node * insert(struct tree_node *root,struct tree_node *element){
   //Element is inserted as root if NULL
   if(root == NULL){
       return element;
   }
   //Greater element should be inserted to the right.
   if(element -> income > root -> income)
   {
	   // There is a right subtree to insert the node.
       if(root-> right != NULL){
           root -> right = insert(root -> right,element);
	   }
	   // Place the node directly to the right of root.
       else{
           root -> right = element;
	   }
   }
   // element should be inserted to the left.
   else
   {
	   // There is a left subtree to insert the node
       if(root -> left!=NULL){
           root -> left = insert(root -> left,element);
       }
	   // Place the node directly to the left of root.
	   else{
           root -> left = element;
	   }
   }
   return root;
}

//Tree node for odd number people count
//Write a function that prints all the incomes with odd number of people count.
//oddPeople
/*void oddNode(Node* root)
{
    if (root != NULL) {
        oddNode(root->left);
  
        // if node is odd then print it
        if (root->key % 2 != 0)
            printf("%d ", root->key);
  
        oddNode(root->right);
    }
}

*/


//Tree node for highest income
//Write a function to find the total number of people 
//having the highest income from your tree.
struct tree_node* peopleWithHighestIncome(struct tree_node *root)
{
   while(root -> right != NULL)
       root = root -> right;
   return root;
}


//Main function
int main(){
	//Read input file and write output file
	FILE *fp = fopen("in.txt", "r");
	FILE *fout = fopen("out.txt", "w+");
	int n;
	fscanf(fp, "%d", &n);
	struct tree_node *root = NULL;
	for(int i = 0; i < n; i++){
		int size;
		int count;
		fscanf(fp,"%d %d",&size,&count);
		struct tree_node *node=(struct tree_node *)malloc(sizeof(struct tree_node));
		node -> income = size;
		node -> count = count;
		node -> left = NULL;
		node -> right = NULL;
		root = insert(root,node);
	}
	printf("Tree constructed from the file\n");
	fprintf(fout, "In order: ");
	printf("In order: "); 
	inorder(root,fout);
	fprintf(fout,"\n");
	printf("\n");
	//fprintf(fout,"Incomes with Odd number of people count: %d\n", oddPeople->income);
	//printf("Incomes with Odd number of people count: %d\n", oddPeople->income);
	struct tree_node *HighestIncome=peopleWithHighestIncome(root);
	fprintf(fout,"Total people with highest income: %d\n",HighestIncome->count);
	printf("Total people with highest income: %d\n",HighestIncome->count);
	fclose(fp);
	fclose(fout);
}