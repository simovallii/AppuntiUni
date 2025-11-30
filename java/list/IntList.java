package it.unipr.list;

public class IntList {

	private Elem list;
	private int n;
	
	public IntList() {
		
		this.list = null;
		this.n = 0;
	}
	
	public void addFirst(int x) {
		Elem newElem = new Elem(x, this.list);
		this.list = newElem;
		n++;
	}
	
	public int removeFirst() {
		
		int r = this.list.getData();  // controllo se lista non è nulla;
		this.list = this.list.getNext();
		
		return r;
	}
	
	public int addLast(int x) {
		
		Elem cpy = this.list;
		
		while (cpy.getNext() != null) {
			cpy = cpy.getNext();
			
			Elem newElem = new Elem(x, null);
			cpy.setNext(newElem);
			this.n++;
  		}
		
		return x;
	}
}
