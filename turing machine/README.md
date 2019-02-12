DETERMINISTIC TURING MACHINES : The goal of this problem is to write a function that simulates the execution of a Turing machine. A Turing Machine is formally defined as a 6-tuple (Q, Σ, δ, q0, qaccept, qreject). We first need to define a data-structure to encode Turing machines. Without loss of generality, we can assume that Q is modelled with integers and Σ with characters, which are both primitive types in Python. The transition function δ is usually defined as a function δ: Q x Σ -> Q x Σ x {L,R}. Strictly, this definition corresponds to a complete Turing machine, analoguous to complete-DFA. In practice, it will be more convenient to work with transition functions that are not necessarily complete. Therefore, a more adequate representation for a partial function δ is a list of transitions, where each transition is encoded as a quintuple: { (q,a,q',b,m) | δ(q,a) = (q',b,m) }. In Python, we encode δ as a list containing lists of 5 elements. To interpret this list of transitions as the function δ, we define a function delta() that takes a list of transitions lst, a pair q,a, and returns the triple (q',b,m) when (q,a,q',b,m) is in the list lst. A move instruction is encoded by the strings "Left" , "Right", or "Stay". We assume that the list lst does not contain several 5-tuples starting with q and a because the Turing machine is deterministic. Complete the following skeleton code for delta() and notice that the function is recursive, it returns the empty list when no transition is found, and a list of three elements otherwise:

def delta(lst,q,a):
  if lst == []:
    return []
  else:
    ...
    if ... :
      return [q', b, m]
    else:
      return delta(lst[1:],q,a)

A Turing machine is encoded using a class:

class TM:
  def __init__(self,transitions,qstart,qaccept, qreject):
    self.transitions = transitions
    self.qstart = qstart
    self.qaccept = qaccept
    self.qreject = qreject

Next, to encode the tape with the head, let us use the mathematical specification we used in class, that is a tape with its head is an element of (Σ * x Σ x Σ *). This will prove to be efficient when dealing with nondeterminisitic Turing machines in the next section.

class TapeHead:
  def __init__(self, left = [], head = '_', right = []):
    self.left = left
    self.head = head
    self.right = right

The three types of operations that can be performed on a tape by a Turing machine is replace the symbol pointed by the head with another symbol, and moving the head left or right. For example, the tape (abc, d, efg) is encoded as TapeHead(['a','b','c'], 'd', ['e','f','g']). Moving the head to the right would produce a TapeHead(['a','b','c','d'], 'e', ['f','g']). Moving the head to the left would produce a TapeHead(['a','b'], 'c', ['d','e','f','g']). Do not forget the special cases when the head is at the leftmost position of the tape or when the head is at the rightmost position of the tape.

Implement these tape operations, making sure that the TapeHead is a persistent data structure, which means that the operations should not modify in place each field but instead create a new TapeHead object with modified fields. In practice, to make it persitent, you simply have to use the following basic operations on strings: concatenation +, selecting the head of a list with lst[0], get the tail of a list lst[1:], and get a list without its last element lst[:-1]. Implement functions moveLeft(), moveRight() and replace() that take as input a tape with its head, and returns the new tape with head according to the operation.

def moveLeft(tapehead):
  ...
  return TapeHead(u,a,v)

def moveRight(tapehead):
  ...
  return TapeHead(u,a,v)

def replace(tapehead,b):
  ...
  return TapeHead(u,a,v)

A configuration from (Q x TapeHead) can simply be encoded with a list containing with two elements, the current state and the current tapehead. Write a function init() that returns the initial configuration for an input Turing machine and a given input string w.

def init(tm,w):
  ...

Write a function onestep() that simulates a single step of computation of a Turing machine given a configuration. The function onestep() must return the next configuration.

def onestep(tm,q,tapehead):
  ...

Using the previous function onestep(), write a function called allsteps() that computes iteratively all the steps until it reaches an halting state, that is the accept state or the reject state. This function should be recursive and return a halting configuration if the machine halts, or loop forever if that is what the machine is intended to do.

def allsteps(tm,q,tapehead):
  ...

Finally, define a function simulation() that takes as input a Turing machine and an input string and executes the machine on the input string. The function simulation() uses init() and allsteps and returns a boolean indicating if the input string is accepted or rejected, or it loops forever.

def simulation(tm,w):
  ...


https://www.khanacademy.org/computer-programming/turing-machine/938201372

https://introcs.cs.princeton.edu/java/52turing/

http://www.cs.princeton.edu/courses/archive/fall09/cos126/assignments/theory.html


Construct a Turing machine that adds two binary integers. Your Turing machine must be a single tape, one way infinite, deterministic Turing machine. When the Turing machine completes, the tape should contain Z, where Z = X + Y. You do not need to delete X#Y from the tape, you can simply position the Turing machines read/write head at the beginning of Z.
For this, An input will be of the form X#Y, where X and Y are elements of {0, 1}. In particular, X = xnxn-1... x1x0, and Y = ymym-1... y1y0, with xi, yi in {0, 1}, X = (xnx 2n) + (xn-1x 2n-1) + ... + (x1x 21) + (x0x 20), and Y = (ymx 2m) + (ym-1x 2m-1) + ... + (y1x21) + (y0x20).

Construct a Turing Machine that increments a Binary number.

Write a classical Turing machine program that ‘accepts’ the language L = { anbncn | n >= 0 }: the program yields the result ‘Y’ if the argument string w ∈ {a, b, c}∗ is in L, and ‘N’ if it is not. For example, input “aabbcc” yields output “Y”, since aabbcc ∈ L, and input “bbaaccc” yields output “N”, since bbaaccc does not belong to L.
