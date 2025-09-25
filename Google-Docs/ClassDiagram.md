# UML Class Diagram - GraphyDocs

```mermaid
classDiagram
    %% Abstract Classes and Interfaces
    class DocumentElement {
        <<abstract>>
        +render() void
    }
    class TextElement {
        +render() void
    }
    class ImgElement {
        +render() void
    }

    class Persistence {
        <<abstract>>
        +save(data: string) void
    }
    class FileStorage {
        +save(data: string) void
    }
    class DBStorage {
        +save(data: string) void
    }

    %% Core Model
    class Document {
        -elements : Vector~DocumentElement~
        +addElement(element: DocumentElement) void
        +getElements() : Vector~DocumentElement~
    }

    %% Renderer
    class DocumentRenderer {
        +render(doc: Document) void
    }

    %% Editor / Controller
    class DocumentEditor {
        -doc : Document
        -storage : Persistence
        +addText(txt: string) void
        +addImage(path: string) void
    }

    class Client

    %% Relationships
    DocumentElement <|-- TextElement
    DocumentElement <|-- ImgElement

    Persistence <|-- FileStorage
    Persistence <|-- DBStorage

    Document "1" --> "*" DocumentElement
    DocumentRenderer --> Document
    DocumentEditor --> Document
    DocumentEditor --> Persistence
    Client --> DocumentEditor
