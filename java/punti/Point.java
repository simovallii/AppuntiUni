package it.unipr.punti;

public class Point {
	
	protected int x;
	protected int y;
	
	Point(){
		this(0,0);
	}
	public Point(int x, int y){
		this.x = x;
		this.y = y;
	}
	
	public String toString() {
		return this.x + "," + this.y;
	}
	
	public int moveX(int newX) {
		
		this.x += newX;
		return x;
	}
	
	public int moveY(int newY) {
		
		this.y += newY;
		return y;
	}
	
	public boolean equals(Object obj) {
		
		if (this == obj) 
			return true;
		else if (obj == null)
			return false;
		else if(this.getClass() != obj.getClass())
			return false;
		
		Point other = (Point) obj;
		return this.x == other.x && this.y == other.y;
		
	}
}
