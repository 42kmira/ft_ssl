
<br>
<img align="left" height="250" src="https://github.com/42kmira/ft_ssl/blob/master/resources/Untitled.png" />
<br>

This is the introductory project for the security branch at 42 Silicon Valley.

In this project we implement in C the hash functions MD5 and SHA256. For bonus I also implemented
SHA224, SHA384, and SHA512. This implementation reads the string or file in chunks, much like the most official
implementations, as opposed to reading the entire thing string or file. It also uses a dispatch table that has each
different hash function, making it easy to remove, or add new hash functions.

After the executable is made using the Makefile usage is:

```./ft_ssl < Hash Function > [-pqr] [-s string] [file ...]```

Below is a comparision of my program with the default openssl and md5 imlementation found on MacOS:

<br>
<img align="left" height="450" src="https://github.com/42kmira/ft_ssl/blob/master/resources/mine.gif" />
<br>

<br>
<img align="left" height="450" src="https://github.com/42kmira/ft_ssl/blob/master/resources/system.gif" />
<br>
