# Walnut

A **super** simple static site generator built to learn C++.

### Why?

Just wanted a more "real world" project to build to help me learn C++.
I don't recommend actually using this.  If you're looking for a good static
site generator check out:

* [Gatsby](https://www.gatsbyjs.org/)
* [Hugo](https://gohugo.io/)
* [Jekyll](https://jekyllrb.com/)

### Features

* `walnut.toml` configuration for different site structures
* very primitive layouts using `{{content}}` directive
* markdown --> html parsing.
* js/css/image support 
* partials via `{{include my_partial.html}}` directives
* ... that's it for now!  Should be enough to build simple websites.

### Configuration

| Key | Description | Default Value |
|-------|-------------|-------------|
| `contentDir` | Where your .md files live | `content` |
| `assetDir` | Where your .css/.js files live | `assets` |
| `includeDir` | Where your partials live | `include` |
| `layoutDir` | Where your layouts live | `layouts` |
| `distDir` | Where your static site gets compiled to | `dist` |

### Layouts

Layouts are just HTML files that live in your configured `layoutDir`. Each
markdown file that gets processed will get injected wherever you have a
`{{content}}` directive.  Simple example:

```html
<!DOCTYPE html>
<html>
    <head>
        <meta charset="utf-8" />
        <meta name="viewport" content="width=device-width" />
        <title>A Simple Website</title>
        <link rel="stylesheet" href="./assets/styles.css">
    </head>
    <body>
        {{content}}
    </body>
</html>
```

### Partials 

Common HTML elements can be extracted into partials and then injected into
templates in various locations.  Partials are just html files that live in your
`includeDir` and can be injected using the `{{include myPartial.html}}`
directive.  Simple example:


**Layout #1**
```html
<!DOCTYPE html>
<html>
    <head>
        <meta charset="utf-8" />
        <meta name="viewport" content="width=device-width" />
        <title>A Simple Website</title>
        <link rel="stylesheet" href="./assets/styles.css">
    </head>
    <body>
        {{include header.html}}
        {{include sidebar.html}}

        {{content}}

        {{include footer.html}}
    </body>
</html>
```

**Layout #2**
```html
<!DOCTYPE html>
<html>
    <head>
        <meta charset="utf-8" />
        <meta name="viewport" content="width=device-width" />
        <title>A Simple Website</title>
        <link rel="stylesheet" href="./assets/styles.css">
    </head>
    <body>
        {{content}}
        {{include sign-up-form.html}}
    </body>
</html>
```

### TODO

- [ ] better templating
- [ ] dev server
- [ ] file watching to recompile
- [ ] better markdown parsing (github flavored perferrably)
- [ ] CLI with different targets (new, build, serve, watch, etc.)
- [ ] Ability to turn on/off different plugins?
