### Postpone variable definitions as long as possible.
There's a cost associated with unused variables, so you want to avoid them whenever you can. Not only should you postpone a variable's definition until right before you have to use the variable, you should also try to postpone the definition until you have initialization arguments for it. 

But what about loops? For classes where an assignment costs less than a constructor-destructor pair, defining outside is generally more efficient. Otherwise you should default to define within.

#### THINGS TO REMEMBER
* Postpone variable definitions as long as possible. It increases program clarity and improves program efficiency.
