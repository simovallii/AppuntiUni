interface Expr
class Num(val value: Double) : Expr
class Sum(val left: Expr, val right: Expr) : Expr
class Sub(val left: Expr, val right: Expr) : Expr
class Mult(val left: Expr, val right: Expr) : Expr
class Div(val left: Expr, val right: Expr) : Expr

fun eval(e : Expr) : Double =
    when(e){
        is Num -> e.value
        is Sum -> eval(e.left) + eval(e.right)
        is Sub ->eval(e.left) - eval(e.right)
        is Mult -> (eval(e.left) * eval(e.right))
        is Div -> (eval(e.left) / eval(e.right))
        else -> throw IllegalArgumentException("Unknown expression")
    }

fun main(){

   val res = eval(Sum(Num(5.0), Div(Num(4.0),Mult(Num(2.0),Sub(Num(3.0),Num(1.0))))))
    println(res)
}