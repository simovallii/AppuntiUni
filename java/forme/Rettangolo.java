package it.unipr.forme;

public class Rettangolo {
	
	protected final int b;
	protected final int h;
	
	public Rettangolo() {
		this(1,1);
	}
	public Rettangolo(int b, int h) {
		
		this.b = b;
		this.h = h;
	}
	
	public int perimetro() {
		
		return (b + h)* 2;
	}
	
	public int area() {
		
		return (b*h)/2;
	}
	
	public String toString() {
		return b + ", " + h;
	}
	
	public boolean equals(Object obj) {
		
		if (this == obj)
			return true;
		if (obj == null)
			return false;
		if (!(obj instanceof Rettangolo))
			return false;
		
		Rettangolo other = (Rettangolo) obj;
		return this.b == other.b && this.h == other.h;
	}
}
