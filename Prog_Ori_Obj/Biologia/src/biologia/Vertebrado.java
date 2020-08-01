package biologia;

public abstract class Vertebrado extends Animal {

  public String quemSou() {
    return super.quemSou() + " vertebrado"; 
  }

}
