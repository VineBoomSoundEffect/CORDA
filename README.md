# CORDA
A software for writing words instead of letters
## KEEP IN MIND
#### The software is still in developement!
## What is Corda?
Corda is a software that allows you to chord keys on your keyboard to make words, similar to stenography, except it uses all the keys on your keyboard.
## How does it work?
To begin chording, you must have a **dictionary**, which is a `.txt` file located in the `%localappdata%\corda` folder. If you never had corda before, create the `corda` subfolder.
## Let's make a dictionary!
Suppose we want to create a dictionary called `dict.txt` that lets us type `Hello, World!` and `Three, Two, One, GO!` in simple strokes.<br>
Here is how the file would look like:<br>
`hw`<br>
`Hello, World!`<br>
`3g`<br>
`Three, Two, One, GO!`<br>
The letter of a chord is what comes out of your keyboard when you type it. The syntax is **CHORD**, then **message** on a new line, then chord on a new line, and so on.
## Now, let's run corda!
You can run Corda by downloading the `.exe` file. In the terminal, type `corda [arg]`, where arg is the name of the dictionary we want to use, without the .txt extension. In our case, we will write `corda dict`.<br>
You will be greeted with the message:<br>
`The program has started.`<br>
Make a chord by typing the letters of the chord at the same time, together with a **`**(aka **~**).
## Do I have to MAKE the dictionaries?
For now, yes. I will try to post some dictionaries soon. Don't forget that this is only an early developement stage, so there is not too much to expect.
