# Design Patterns

Design patterns are proven solutions to common problems in software design. They represent best practices that experienced developers use to solve recurring problems in a consistent and reusable way. Design patterns are like templates that can be applied to various scenarios, providing a blueprint for solving problems and building efficient, maintainable, and scalable software.

## Categories of Design Patterns

### 1. Creational Patterns
Deal with object creation mechanisms, trying to create objects in a manner suitable for the situation. Examples include Singleton, Factory, and Abstract Factory patterns.

### 2. Structural Patterns
Concerned with the composition of classes or objects. It helps to simplify the design of complex structures by identifying relationships and interactions between entities. Examples include Adapter, Composite, and Proxy patterns.

### 3. Behavioral Patterns
Focus on communication between objects and how responsibilities are distributed. Examples include Strategy, Observer, and Command patterns.

## Factory Design Pattern

### Problem Addressed
The Factory Design Pattern addresses the problem of creating objects without specifying the exact class of object that will be created. This is useful when the specific classes that need to be instantiated may not be known until runtime or the code may need to handle different types of objects that share a common interface or base class.

#### Issues:
- Tight Coupling: Directly instantiating specific classes in client code leads to tight coupling, making the system hard to maintain and extend.

### Solution Provided
The Factory Design Pattern provides a solution by creating objects through a common interface or abstract class, allowing subclasses to determine the specific types of objects to be created. This promotes loose coupling and enhances flexibility and maintainability.

### When to Use
- When you want to encapsulate object creation.
- When you want to decouple client code from concrete classes.
- When you need to support multiple product variations.
- When you want to support customization or configuration.

### Components
- **Product Interface or Abstract Class:** Defines the methods and properties that the concrete products must implement.
- **Concrete Products:** Specific implementations of the product interface.
- **Creator Class:** Contains the factory method, either abstract or with a default implementation.
- **Concrete Creator:** Subclasses of the Creator that implement the factory method to create specific types of objects.

## Composite Design Pattern

### Problem Addressed
The Composite Pattern addresses the problem of treating individual objects and composite objects uniformly. Without it, client code would need to differentiate between simple and composite objects, making the system more complex and harder to maintain.

### Key Concepts and Components
- **Component Interface:** Common interface for all objects in the composition, defining the operations that can be performed.
- **Leaf:** Basic building block in the composite structure, representing an individual object with no children.
- **Composite:** Contains other components (either leaves or other composites) and manages its children.

## Strategy Design Pattern

### Problem Addressed
The Strategy Pattern addresses the problem of having multiple algorithms for a specific task and the need to choose between them dynamically. Without it, a client might implement multiple conditional statements to select the appropriate algorithm, leading to complex and hard-to-maintain code.

### Key Concepts and Components
- **Strategy Interface:** Defines a common interface for all supported algorithms.
- **Concrete Strategies:** Implement the algorithm defined by the Strategy interface.
- **Context:** Contains a reference to a Strategy object and interacts with the Strategy interface to execute the algorithm.

## Builder Design Pattern

### Problem Addressed
The Builder Pattern addresses the problem of constructing complex objects that require multiple steps or configurations. Without it, the client code would need to create objects with numerous parameters, leading to large and unreadable constructor calls or inconsistent object states.

### Key Concepts and Components
- **Builder Interface:** Defines methods for constructing different parts of the product.
- **Concrete Builder:** Implements the Builder interface and provides specific implementations for the construction steps.
- **Product:** Represents the complex object being constructed.
- **Director:** Manages the construction process using the Builder interface.

## Adapter Design Pattern

### Problem Addressed
The Adapter Pattern solves the problem of integrating existing components or systems that were not designed to work together due to incompatible interfaces. Without it, modifying existing code to make different systems compatible would be difficult and error-prone.

### Key Concepts and Components
- **Target Interface:** Defines the interface expected by the client.
- **Adaptee:** Existing class with an incompatible interface.
- **Adapter:** Class that implements the target interface and internally uses an instance of the adaptee.

## Observer Design Pattern

### Problem Addressed
The Observer Pattern addresses the problem of ensuring that multiple objects are automatically notified and updated when another object changes state. Without it, keeping dependent objects in sync would require manual updates, leading to tightly coupled code and potential inconsistencies.

### Key Concepts and Components
- **Subject:** Maintains a list of observers and provides methods to attach or detach observers.
- **Observer:** Defines an interface for objects that should be notified of changes in the subject.
- **Concrete Subject:** Implements the Subject interface and stores state that may change.
- **Concrete Observer:** Implements the Observer interface and updates its state in response to changes in the subject.

## Decorator Design Pattern

### Problem Addressed
The Decorator Pattern is used to add new behavior or functionality to an existing object without altering its structure. It is particularly useful for providing runtime modification abilities, making it more flexible and easy to maintain.

### Procedure
1. Create an interface.
2. Create concrete classes implementing the same interface.
3. Create an abstract decorator class implementing the same interface.
4. Create a concrete decorator class extending the abstract decorator class.
5. Use the concrete decorator class to decorate interface objects.

## Facade Design Pattern

### Problem Addressed
The Facade Pattern provides a simplified interface to a complex subsystem. It hides the complexities of the subsystem and provides a unified interface that is easier to use.

### Example
Think of a home theater system with various components like a TV, sound system, and Blu-ray player. A remote control can act as a facade, offering a simplified interface to control the entire system.

## State Design Pattern

### Problem Addressed
The State Pattern allows an object to change its behavior when its internal state changes. It encapsulates state-specific behavior within state objects and delegates state-specific requests to these objects.

### Key Concepts and Components
- **Context:** Object that has an internal state and whose behavior changes based on that state.
- **State Interface:** Defines the interface for encapsulating the behavior associated with a particular state of the context.
- **Concrete States:** Classes that implement the state interface and define the behavior for a particular state of the context.

<br/>

# 

For More Details, read this doc: [Design Patterns](url)
