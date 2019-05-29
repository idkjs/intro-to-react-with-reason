module AlertContainer = {
  [@react.component]
  let make = (~children) => {
    <>
      <pre className="mb-2">
        <code>
          "[@react.component] [@bs.module]
external make: (~isVisible: bool=?, ~_type: string=?, ~message: string) => React.element = \"./Alert\";"
          ->Utils.str
        </code>
      </pre>
      children
    </>;
  };
};

[@react.component]
let make = () => {
  let url = ReasonReactRouter.useUrl();
  <>
    <Header.component />
    <main className="container px-4">
      {switch (url.path) {
       | [] => <Home.component />
       | ["intro"] => <Intro.component />
       | ["login"] => <Login.component />
       | ["search"] => <Search.component username={url.search} />
       | ["vanilla-react"] when url.search !== "" =>
         <AlertContainer> <Alert _type="success" message={url.search} /> </AlertContainer>
       | ["vanilla-react"] =>
         <AlertContainer> <Alert _type="info" message="Play with the query params" /> </AlertContainer>
       | _ => <AlertContainer> <Alert _type="error" message="Route not found" /> </AlertContainer>
       }}
    </main>
    <footer className="flex flex-grow justify-center items-center p-2"> "Made with <3"->Utils.str </footer>
  </>;
};