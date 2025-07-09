# API, Libraries and Packages

## Install&#x20;

### API-Package

1. In Release select Tag `API`.
2. Download the Package for the desired Programming Languages
3. Insert the files into the Project Root
4. Import the `moo.*` and create an instance. It will then load the `.dll/.so./dylib` automatically.



### Package

1. Open your shell and type the download for the package.
2. Import then the package and create an instance. It will work just as fine as with API-Package. But it will not be portable by some programming languages.



### Library

1. Go to Release and select Tag `Library`
2. Go to your C++ or C Project and import the file `moo.hpp` or `moo.h`





## Usage of API

{% tabs %}
{% tab title="JS+TS Deno" %}
```c
import { moo } from "./moo.deno.ts";
const moo = new moo();

// or

import { moo } from "https://deno.land/x/moo@vx.x.x/moo.ts";

```
{% endtab %}

{% tab title="JS Node" %}
```javascript
const { moo } = require("./moo.node.js");

const moo = new moo();
```
{% endtab %}

{% tab title="Python" %}
```python
import moo

m = moo.moo()
```
{% endtab %}
{% endtabs %}

