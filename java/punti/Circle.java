package it.unipr.punti;

public class Circle extends Point{
	
	private int r;
	
	public Circle() {
		
		super(0,0);
		this.r = 1;
	}
	
	
	public Circle(int x, int y, int r) {
		
		super(x, y);
		this.r = r;
	}

	public Circle(int x, int y) {
	
		super(x, y);
		this.r = 1;
	}
	
	public int modify(int x) {
		
		this.r *= x;
		return r;
	}
	
	public String toString() {
		return super.toString() + this.r;
	}
	
	public boolean equals(Object obj) {
		
		if(this == obj)
			return true;
		else if(obj == null)
			return false;
		else if(this.getClass() != obj.getClass())
			return false;
		
		Circle other = (Circle) obj;
		return super.equals(other) && this.r == other.r;
	}
}
