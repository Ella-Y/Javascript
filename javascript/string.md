## String과 Object
string은 절대 ```new```키워드를 이용해서 작성하면 안된다.
y는 아무리 string으로 작성했더라도 Object type이 된다.
```js
var x="hello!"; //type: string
var y=new String("hello!"); //type: Object

console.log(x==y) //true 같은 value를 가지고 있기 때문에
console.log(x===y) //false 같은 타입을 가지고 있지 않기 때문에
```
둘다 오브젝트로 선언되었을 때 **항상 false**라는 처참한 결과를 가져온다.
```js
var x=new String("hello!")
var y=new String("hello!");

console.log(x==y) //false 사실 Object는 비교될 수 없다.
console.log(x===y) //false 
```
## String Methods and Properties
> Object는 Methods와 속성을 가지지 않는다.
>
> 모든 string메소드는 새로운 string을 반환하고 기존의 string은 변경이 없다.

### String length
```js
var txt = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
var sln = txt.length;
```

### Find a string in a string
text를 찾지 못하면 -1을 반환한다.
#### indexOf
```js
var str = "Please locate where 'locate' occurs!";
var pos = str.indexOf("locate");
console.log(pos); //7
```
0번부터 시작하기 때문에, locate의 시작 위치는 7이다. 가장 처음에 나오는 단어 기준이다.
> Please **locate** where...

P,l,e,a,s,e, ,l -> 0,1,2,3,4,5,6,7

#### lastIndexOf
> Please locate where **'locate'** occurs!
```js
var str = "Please locate where 'locate' occurs!";
var pos = str.lastIndexOf("locate");
console.log(pos); //7
```

#### 두번째 파라미터
둘다 두번째 파라미터로 시작위치(숫자)를 받는다. 해당 위치에서부터 시작해서 단어를 찾으라는 의미이다.
```js
str.lastIndexOf("locate",10);
str.indexOf("locate",10);
```
### Searching for a String in a String
text를 찾지 못하면 -1을 반환한다.

```search()```는 indexOf랑 비슷한 일을 하지만 항상 처음 나오는 것만 반환한다. (두번째 파라미터도 없다.) 대신에 regExp를 이용하여 찾을 수도 있다. (단, indexOf는 이런일을 하지 못한다.)

### Extracting String Parts
문자 추출하기

- slice(start, end)
    - 새로운 string을 반환한다. 음수도 가능하다(음수는 뒤에서 부터 파이썬처럼..)
    - end 값을 생략하면 시작위치부터 끝까지이다.
    - 음수는 ie8 과 이전버전에서 동작하지 않는다.
- substring(start, end)
    - 음수는 사용할 수 없다.
    - end 값을 생략하면 시작위치부터 끝까지이다.
- substr(start, length)
    - 시작위치부터 **길이**이다.
    - end 값을 생략하면 시작위치부터 끝까지이다.

### Replacing String Content
#### replace(targetstr, changestr)
- replace를 이용해서 string에 변화를 줄때, 해당 string에 변화가 있는게 아니라 **새로운 string을 반환** 한다.
- 가장 처음 매칭된 것만 바꾼다.
- 기본적으로 대소문자를 구분한다.
    - Naver 대신에 naver라면 바뀌는 것은 없다.
- Regular expression을 사용할 수 있다.(targetstr 에)
```js
    var str = "Please visit Naver and Naver!";
    var n = str.replace("Naver", "github");
    console.log(n); //Please visit github and Naver!
```

### Extracting String Characters
- charAt(position)
- charCodeAt(position) : UTF-16 code(0~65535 까지의 int)를 return
- [ ]
```js
var str = "HELLO WORLD";
str.charAt(0); // returns H
str[0];  // returns H
str.charCodeAt(0); // returns 72
str[0]='A';
str[0]; //returns H
```
>[  ]는 string이 마치 array인 것 같은 착각을 만드니까 지양하는것이 좋다.
>
>왜냐하면, **readOnly**이기 때문이다. ```str[0]='A'``` 처럼 절대 동작할 수 없다. 
>
>만약에 string안의 내용을 바꾸고 싶으면, array로 바꾸어서 수행해야 한다.

### Converting a String to an Array
```split()```메소드를 이용해서 string을 array로 변경할 수 있다.
```js
var txt = "a,b,c,d,e";  // String
var ary=txt.split(","); // Split on commas
console.log(ary); //a,b,c,d,e
console.log(ary.length); //5

var ary2=txt.split("|"); //split on pipe
console.log(ary2); //a,b,c,d,e
console.log(ary2.length); //1
```

### etc
- toUpperCase()
- toLowerCase()
- concat(): +와 같은 역할
- trim()
```js
//concat
var str1="hello";
var str2="world";
var result=str1.concat(str2);
```
```js
//IE8 Supports trim
if (!String.prototype.trim) {
  String.prototype.trim = function () {
    return this.replace(/^[\s\uFEFF\xA0]+|[\s\uFEFF\xA0]+$/g, '');
  }
};
var str = "       Hello World!        ";
alert(str.trim());
```


### 특수문자 사용 방법
<table>
<tbody><tr>
  <th width="25%">Code</th>
  <th>Result</th>
  <th>Description</th>
</tr>
<tr>
  <td>\'</td>
  <td>'</td>
  <td>Single quote</td>
</tr>
<tr>
  <td>\"</td>
  <td>"</td>
  <td>Double quote</td>
</tr>
<tr>
  <td>\\</td>
  <td>\</td>
  <td>Backslash</td>
</tr>
</tbody></table>