package view;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

import modelo.Usuario;

public class Interface {
  
  private static List<Usuario> cadastrados = new ArrayList<Usuario>();
  private static Usuario logado;

  public static void main(String[] args) {
    char o;
    Scanner s = new Scanner(System.in);
    do {
      System.out.println("Opções:");
      System.out.println("c - cadastrar novo usuário.");
      System.out.println("l - logar com usuário existente.");
      System.out.println("s - sair.");
      System.out.print("> ");
      o = s.nextLine().charAt(0);
      switch(o) {
      case 'c':
        realizaCadastro(s);
        break;
      case 'l':
        realizaLogin(s);
        break;
      }
    } while (o != 's');
    s.close();
  }

  private static void realizaLogin(Scanner s) {
    System.out.println("Login");
    System.out.println("Entre com o seu email:");
    String email = s.nextLine();
    System.out.println("Entre com a senha:");
    String senha = s.nextLine();
    for(Usuario u : cadastrados) {
      if(u.getEmail().equals(email)) {
        if(u.getSenha().equals(senha)) {
          System.out.println("Usuário logado.");
          System.out.println("Bem-vindo " + u.getNome());
          logado = u;
        }
      }
    }
  }

  private static void realizaCadastro(Scanner s) {
    System.out.println("Cadastro");
    Usuario novo = new Usuario();
    System.out.println("Entre com o seu nome:");
    System.out.print("> ");
    String nome = s.nextLine();
    novo.setNome(nome);
    System.out.println("Entre com o seu email:");
    System.out.print("> ");
    String email = s.nextLine();
    novo.setEmail(email);
    System.out.println("Entre com o sua senha:");
    System.out.print("> ");
    String senha = s.nextLine();
    novo.setSenha(senha); 
    cadastrados.add(novo);  
   }

}
