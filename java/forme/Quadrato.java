package it.unipr.forme;

public class Quadrato extends Rettangolo{
	
	public Quadrato(int l) {
		
		super(l, l);
	}
	
	public int perimetro() {
		
		return this.b * 4;
	}
	
	public int area() {
		
		return this.b * this.b;
	}
	
	public String toString() {
		return super.toString();
	}
	
	public boolean equals (Object obj) {
		return super.equals(obj);
	}
	public static void main(String[] args) {
		
		Quadrato q = new Quadrato(5);
		Rettangolo r = new Rettangolo(1, 3);
		
		System.out.println(q.area());
		System.out.println(r.area());
	}
}
