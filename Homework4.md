# Homework Assignment 4

## Group 6

### 1.List Some Key Ideas and Best Practices which Will Manifest in Elaboration.
（莫振威）

1. 实现短时间定量、风险驱动的迭代。
2. 及早开始编程
3. 对架构的核心和风险部分进行适应性设计、实现和测试
4. 尽早、频繁、实际地测试
5. 基于来自测试、用户、开发者的反馈进行调整
6. 通过一系列讨论会，详细编写大部分用例和其他需求，每个细化迭代举行一次

### 2.What is a Domain Model? Why Call a Domain Model a "Visual Dictionary"? How to Create a Domain Model?
（胡洁珏、莫振威）

**什么是领域模型？**

A domain model is a visual representation of conceptual classes or real-situation objects in a domain . Domain models have also been called conceptual models , domain object models, and analysis object models.

领域模型是对领域内的概念类或现实世界中对象的可视化表示。领域模型也称为概念模型、领域对象模型和分析对象模型。

In the UP, the term "Domain Model" means a representation of real-situation conceptual classes, not of software objects. The term does not mean a set of diagrams describing software classes, the domain layer of a software architecture, or software objects with responsibilities.

在UP中，术语“领域模型”指的是对现实世界概念类的表示，而非软件对象的表示。该术语并不是指用来描述软件类、软件构架领域层或有职责软件对象的一组图

The UP defines the Domain Model as one of the artifacts that may be created in the Business Modeling discipline. More precisely, the UP Domain Model is a specialization of the UP Business Object Model (BOM) "focusing on explaining 'things' and products important to a business domain". That is, a Domain Model focuses on one domain.

UP对领域模型的定义是，可以在业务建模科目中创建的制品之一。更准确地讲，UP领域模型是UP业务对象模型（BOM）的特化，“专用于解释业务领域中重要的‘事物’和产品”。也就是说，领域模型专注于特定领域。

Applying UML notation, a domain model is illustrated with a set of class diagrams in which no operations (method signatures) are defined. It provides a conceptual perspective. It may show:

- domain objects or conceptual classes 
- associations between conceptual classes 
- attributes of conceptual classes
  
应用UML表示法，领域模型被描述为一组没有定义操作（方法的特征标记）的类图。它提供了概念透视图。它可以展示：

- 领域对象或概念类
- 领域类之间的关系
- 领域类的属性

**为什么将领域模型称为“可视化字典”？**

领域模型描述的信息也可以采用纯文本方式表示。但是在可视化语言中更容易理解这些术语，特别是它们之间的关系，因为我们的思维更擅长理解形象的元素和线条连接。因此，领域模型是可视化字典，表示领域的重要抽象、领域词汇和领域的内容信息

**怎样创建领域模型？**

以当前迭代中索要设计的需求为界：寻找概念类、将其绘制为UML类图中的类、添加关联和属性

### 3.What are Conceptual Classes? How do I find Conceptual Classes?
（李浩天）

**什么是概念类？**

领域模型阐述领域中的概念类或词汇。概念类是现实世界中的思想,概念,对象和事物。可以从其符号(词语和图形),内涵(定义)和外延(一组实例)来考虑。内涵是概念类的定义，外延是概念类所适用的一组示例。

**怎样找到概念类？**

寻找概念类是构建领域模型的关键,一般的构建方法有三种：

1. 重用和修改现有的模型：某些概念类可能在许多领域都存在并已经发布了，可以将直接使用或者细化；
2. 使用分类列表：根据实际业务的重要性赋予优先级来创建概念类候选列表；
3. 确定名词短语，在对领域的文本性描述中识别名词与名词短语,将此作为候选的概念或者属性。

### 4.What are Associations in a domain model? How to find associations for a domain model?
（陈家龙）

**在领域模型中，什么是关联？**

关联是类（更准确地说，是这些类的实例）之间的关系，表示有意义和值得关注的连接。在UML中，关联被定义为“两个或多个类元之间的语义联系，设计这些类元实例之间的连接”。这些关系根据语境，存在的时间可能不同。需要特别注意的是，关联不表示数据流或者数据库之间的关系，它针对的是从纯概念之间的有意义的关系。关联的存在是为了突出我们对模型中重要关系的理解。

**怎样为领域模型找到关联？**

使用常见关联词列表添加关联。该列表中包含值得考虑的常见类别，对业务信息系统而言更是如此。

首先要基于本次迭代中需要实现的需求，在这个新需求中考量关联可能产生于哪些类的实例之间。其次要对照常见关联列表，考虑哪些实例之间的关联符合“需要被记住”或者值得重点关注这一标准。最后把这些类的实例和符合标准的关联记录下来，绘制成图，便找到了领域模型中的关联。
在常见关联列表中，可以把关联分成以下几种类别：
1. A是与交易B相关的交易
2. A是交易B中的一个项目
3. A是交易（或项目）B的产品或服务
4. A是B的物理或逻辑部分
5. A被逻辑地或物理地包含在B中
6. A是B的描述
7. A在B中被感知/记日志/记录/生成报表/捕获
8. A是B的成员
9. A是B的组织化子单元
10. A使用/管理/拥有B
11. A与B相邻

### 5.When to Define New Data Type Classes for attributes in domain Modeling?
（崔子潇）

确定概念类的属性是有效的，能够满足当前所开发场景的信息需求表。属性是对象的逻辑数据值。当需求建议或暗示需要记住信息时，引入属性。下述情况下，在领域模型内，把最初被认为是数字或字符串的数据类型表示为新的数据类型类：
- 由不同的小节组成，如电话号码、人名。
- 具有与之相关的操作，如解析或校验。
- 具有其他属性，如促销价格的开始日期和结束日期。
- 单位的数量，例如支付总额具有货币单位。
- 具有以上性质的一个或多个类型的抽象。

### 6.What is an System Sequence Diagram (SSD)? What is the Relationship Between SSDs and Use Cases? Why Use SSDs? 
（胡若晴）

**什么是SSD？**

系统顺序图（SSD）是为阐述与所讨论系统相关的输入和输出事件而快速、简单地创建的制品。它们是操作契约和对象设计的输入。在软件工程中，系统序列图（SSD）是一个序列图，它针对用例的特定场景显示外部参与者产生的事件，它们的顺序以及可能发生的系统间事件。

**SSDs和用例之间的关系？**

SSDs展示了用例中一个场景的系统事件，因此它是从对用例的考察中产生的。

**为何使用SSDs?**

因为需要准确的知道什么是外部输入的事件，这些事件是系统行为分析的重要部分。我们必须处理和响应这些事件来设计软件。

软件系统要为如下三种事件响应：来自参与者（人或计算机）的外部事件、时间事件、错误或异常（通常源于外部）。

因此，需要准确地知道，什么是外部输入的事件，即系统事件。这些事件是系统行为分析的重要部分。在对软件应用将如何工作进行详细设计之前，最好将其行为作为“黑盒”来调查和定义。系统行为描述的是系统做什么，而无需解释如何做。这种描述的一部分就是系统顺序图。

### 7.What Are Operation Contracts? How to Create and Write Contracts?
（杨宗恺）

**什么是操作契约？**

操作是对象可能被调用执行的转换或查询的规范。在UML中，操作有一个识别标志（名称和参数），方法是操作的一个实现。

操作契约是相比用例和系统特性，对系统。为的一种更为详细和精确的描述。操作契约使用前置和后置条件的形式，描述领域模型里对象的详细变化，并作为系统操作的结果，有时候也能作为有用的与OOA相关的制品。与系统操作相关的操作契约一般包括操作、交叉引用、前置条件、后置条件四个部分。

操作契约可以视为UP用例模型的一部分，因为它对用例指出的系统操作的效用提供了更详细的分析。

操作契约过于详细，所以不是启动阶段的一部分，一般在细化阶段写操作契约。

**怎样创建和编写操作契约？**

**创建契约时，可以：**

1. 首先从系统顺序图中识别出操作，系统操作是作为黑盒构件的系统在其公共接口中提供的操作。系统操作可以在绘制SSD系统顺序图草图时确定。
2. 然后如果系统操作复杂，结果可能会不明显，在用例中也可能不清楚，就可以为这个系统操作构建一个操作契约。
3. 描述后置条件的类别有：
+ 实例的创建和删除
+ 属性的修改
+ 关联的形成和清除

同时不要遗忘关联的形成，当创建了新实例时，通常需要建立与若干对象的关联。

**编写契约时：**

1. 为了强调变化的观察结果，而非其如何实现的设计，一般以说明性的、被动式的过去时态来编写后置条件，例如“创建了某个Item”，而不是“创建某个Item”。
2. 尽量在已有或新创建的对象之间建立关联，例如对于课件上的例子，在操作enterItem发生时，仅创建SalesLineItem的实例是不够的，操作完成之后，还应该将此新创建的实例Sale关联，例如“将SalesLineItem与Sale关联（形成关联）”。

### 8.Revise the collection of all your artifacts you have done for your first iteration in your Elaboration phase of your project as in the following.
#1.Development Case
#2.Project Vision
#3.Business Case 
#4.Use Case Diagrams
#5.Fully Dressed Use Cases
#6.Domain Model (Conceptual Class Diagrams)
#7.SSD
#8.System Operation Contracts
#9.Supplementary Specification
#10.Glossary
#11.Development Plan
#12.Iteration Plan
#13.System Architecture
Notice that some sections may be empty in your document at this moment. You may also add some supplementary sections in your document.


