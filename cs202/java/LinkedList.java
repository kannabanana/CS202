public class LinkedList {
	private Node head;
	
	public void addToHead(int data) {
		Node temp = head;
		head = new Node();
		head.setData(data);
		head.setNext(temp);
	}


	public void displayAll() {
		if (head == null) {
			System.out.println("Empty list");
			return;
		}
		displayAll(head);
	}


	public void displayAll(Node head) {
		if(head == null) return;
		System.out.println(head.getData());
		displayAll(head.getNext());
	}
}
