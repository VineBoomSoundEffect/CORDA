# CORDA
A software for writing word by word, not letter by letter
## KEEP IN MIND
#### The software is still in developement, also I currently don't accept pull requests.
## What is Corda?
Corda is a software that allows you to chord keys on your keyboard to make words, similar to stenography, except it uses the entire set of letters and numbers.
## How does it work?
To begin chording, you must have a **dictionary**, which is a `.txt` file located in the `%localappdata%\corda` folder. If you never had corda before, create the `corda` subfolder.
## Let's make a dictionary!
Suppose we want to create a dictionary called `dict.txt` that lets us type `Hello, World!` and `Three, Two, One, GO!` in just one stroke.<br>
Here is how the file would look like:<br>
`HW`<br>
`Hello, World!`<br>
`3G`<br>
`Three, Two, One, GO!`<br>
Notice how the chords are always capital letters. The syntax is **CHORD**, then new line, then **message** on a new line, then chord on a new line, and so on.
## Now, let's run corda!
You can run Corda by downloading the `.exe` file. In the terminal, type `corda [arg]`, where arg is the name of the dictionary we want to use, without the .txt extension. In our case, we will write `corda dict`.<br>
You will be greeted with the message:<br>
`The program has started.`<br>
`Press INSERT to toggle on/off.`<br>
By default, Corda is off. You just have to press INSERT on your keyboard, and you're good to go!
## Do I have to MAKE the dictionaries?
For now, yes. I will try to post some dictionaries soon. Don't forget that this is only an early developement stage, so there is not too much to expect.
