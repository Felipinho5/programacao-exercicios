interface Retangulo
{
    void setCatetos(double catetoAdj, double, catetoOpo)
    double calcularHipotenusa()
}

public abstract class Poligono
{
    private int numeroLados;
    
    protected Poligono(int numeroLados)
    public abstract double calcularArea()
}

public class Quadrado extends Poligono
{
    private double tamanhoLado;
    
    public Quadrado(int numeroLados, double tamanhoLado)
    public double calcularArea()
}

public class Triangulo extends Poligono
{
    private double base;
    private double altura;
    
    public Triangulo(int numeroLados, double base, double altura)
    public double calcularArea()
}

public class TrianguloRetangulo extends Triangulo implements Retangulo
{
    private double catetoAdj;
    private double catetoOpo;
    
    public TrianguloRetangulo(int numeroLados, double base, double altura)
    public void setCatetos(double catetoadj, double catetoOpo)
    public double calcularHipotenusa()
}