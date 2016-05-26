import java.util.Scanner;

public class Main {
	public static void main(String [] args) {
		Scanner input = new Scanner(System.in);


		LinkedList linkedList = new LinkedList();		//only making one object-then the object must be lowercase
		int num = 0;
		while(num >= 0) {
			System.out.print("Enter an int: ");
			num = input.nextInt();
			linkedList.addToHead(num);
		}

		linkedList.displayAll();
	}
}
