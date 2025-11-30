package it.unipr.list;

public class Elem {

	private final int data;
	private  Elem next;
	
	public Elem(int data, Elem next) {
		
		this.data = data;
		this.next = next;
	}

	public int getData() {
		return data;
	}

	public Elem getNext() {
		return next;
	}
	
	public void setNext(Elem next) {
		
		this.next = next;
	}
}
