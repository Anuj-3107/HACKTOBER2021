package BinaryTree;

public class TreeTraversal {

	public static void preOrder(BinaryTreeNode<Integer> root) {
		
		if(root == null) {
			return;
		}
		System.out.println(root.data+" ");
		
		preOrder(root.left);
		preOrder(root.right);
		
	}
	
	public static void postOrder(BinaryTreeNode<Integer> root) {
		
		if(root == null) {
			return;
		}
	postOrder(root.left);
	postOrder(root.right);
	System.out.println(root.data);
	
		
	}
	
	public static void unOrdered(BinaryTreeNode<Integer> root) {
		
		if(root ==null) {
			return;
		}
		
		unOrdered(root.left);
		System.out.println(root.data);
		unOrdered(root.right);
		
	}
	
	public static void main(String[] args) {
	
		BinaryTreeNode<Integer> root = new BinaryTreeNode<Integer>(1);
		BinaryTreeNode<Integer> leftChild = new BinaryTreeNode<Integer>(2);
		BinaryTreeNode<Integer> rightChild =  new BinaryTreeNode<Integer>(3);
				root.left=leftChild;
				root.right=rightChild;
		System.out.println("------preOrder-------");
			 preOrder(root);
			 System.out.println("-------postOrder-------");
			 postOrder(root);
			 System.out.println("-------unOrdered-------");
			 unOrdered(root);
			
	}

	
	
	
}
