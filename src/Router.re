[@react.component]
let make = () => {
  let url = ReasonReactRouter.useUrl();
  <>
    <Header />
    <main className="container px-4">
      {switch (url.path) {
       | ["intro"] => <Intro />
       | ["cards"] => <Cards />
       | ["login"] => <Login />
       | ["search"] => <Search username={url.search} />
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
