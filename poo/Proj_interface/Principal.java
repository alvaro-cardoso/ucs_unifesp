package agenda;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Principal {

  private static Agenda a = new Agenda();
  private static Scanner s = new Scanner(System.in);

  public static void main(String[] args) {
    while (true) {

      System.out.println("Menu");
      System.out.println("a - adicionar novo contato");
      System.out.println("b - buscar contato");
      System.out.println("c - alterar contato");
      System.out.println("d - visualizar todos os contatos");
      System.out.println("s - sair");

      char o = s.nextLine().charAt(0);

      switch (o) {
      case 'a':
        System.out.println("Adição de contato");
        adicionaContato();
        break;
      case 'b':
        System.out.println("Busca de contato");
        buscaContato();
        break;
      case 'c':
        System.out.println("Alterar contato");
        break;
      case 'd':
        System.out.println("Visualizar contatos");
        visualizarContatos();
        break;
      case 's':
        System.out.println("Até logo.");
        s.close();
        return;
      default:
        System.out.println("Opção não reconhecida");
      }

    }
  }

  private static void visualizarContatos() {
    for(String nome : a.getAgenda().keySet()) {
      System.out.println("Nome: " + nome);
      Contato c = a.getAgenda().get(nome);
      System.out.println("Emails: " + c.getEmails());
      System.out.println("Telefones: " + c.getTelefones());
    }
  }

  private static void buscaContato() {
    String nome;
    System.out.println("Entre com o nome do contato:");
    nome = s.nextLine();
    Contato c = a.buscaContato(nome);
    if(c != null) {
      System.out.println("Nome: " + nome);
      System.out.println("Emails: " + c.getEmails());
      System.out.println("Telefones: " + c.getTelefones());
    } else {
     System.out.println("Este contato não existe na agenda."); 
    } 
  }

  private static void adicionaContato() {
    String nome;
    List<String> listaEmails = new ArrayList<String>();
    List<String> listaTelefones = new ArrayList<String>();
    System.out.println("Entre com o nome do contato:");
    nome = s.nextLine();
    System.out.println("Nome do contato: " + nome);
    System.out.println("Entre com os seus emails entre vírgulas:");
    System.out.print("> ");
    for(String email : s.nextLine().split(",")) 
      listaEmails.add(email);
    System.out.println("Entre com os seus telefones entre vírgulas:");
    System.out.print("> ");
    for(String telefone : s.nextLine().split(",")) 
      listaTelefones.add(telefone);
    System.out.println("Emails: " + listaEmails);
    System.out.println("Telefones: " + listaTelefones);
    a.adicionaContato(nome, listaEmails, listaTelefones);
  }

}