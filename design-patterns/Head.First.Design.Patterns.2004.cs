using System;

namespace ResumoNamespace
{
    #region Desing principles
    /* Desing principles
     * Identify the aspects of your application that vary and separate them from what stays the same (Encapsulate what varies)
     * Program to interfaces, not to implementations
     * Favor composition over inheritance
     * Strive for loosely coupled designs between objects that interact.
     * Classes should be open for extension, but closed for modification.
     */
    #endregion
    #region Patterns
    /* The Strategy Pattern
    * defines a family of algorithms, encapsulate each one, and make them interchangeable. 
    * Strategy lets the algorithm vary independently from clients that use it.
     */ 
    /* The Observer Pattern
     * Defines a one-to-many dependency between objects so that when one object changes state,
     * all of its dependents are notified and updated automatically.
     */
    /* The Decorator Pattern
     * The Decorator Pattern attaches additional responsibilities to an object dynamically.
     * Decorators provide a flexible alternative to subclassing for extending functionality.
     */
    #endregion

    #region Chapter 1 **Strategy**
    // The Strategy Pattern
    // here we should:
    // *implement flyBehavior and QuackBehavior (algorithms for fly and quack)
    // *extend Duck
    // *Set the behavior of the extended class, using constructor or even dynamically
    // *with setFlyBehavior and setQuackBehavior

    public interface FlyBehavior { 
        void fly();
    }
    public interface QuackBehavior {
        void quack();
    }
    public abstract class Duck {
        FlyBehavior flyBehavior;
        QuackBehavior quackBehavior;
        public Duck() { }
        public abstract void display();
        public void performFly() {
            flyBehavior.fly();
        }
        public void performQuack() {
            quackBehavior.quack();           
        }
        public void swim() {
            System.Console.WriteLine("All ducks float, even decoys!");
        }
        public void setFlyBehavior(FlyBehavior fb) {
            flyBehavior = fb;
        }
    }
    #endregion
    #region Chapter 2 **Observer**
    // The Observer Pattern
    // here we should:
    // *implement the subject interface, add method to inform about state
    // *implement the observer interface, add a Subject and register itself with it
    // *now the Subject can call update(), when there is sth to update
    // *the observer call subject methods to read its state
    public interface Subject {
        public void registerObserver(Observer o);
        public void removeObserver(Observer o);
        public void notifyObserver();
    }
    public interface Observer {
        public void update();
    }
    #endregion
    #region Chapter 3 **Decorator**
    // The Decorator pattern
    // here we should:
    // *
    #endregion


}