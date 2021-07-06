type categoryT =
  | SECONDARY
  | PRIMARY;

let classNameOfCategory = category =>
  "Button "
  ++ (
    switch (category) {
    | SECONDARY => "secondary"
    | PRIMARY => "primary"
    }
  );

[@react.component]
let make =
    (
      ~onClick=_ => (),
      ~title: string,
      ~children: React.element,
      ~disabled=false,
      ~category=SECONDARY,
      ~type_="button",
    ) => {
  <button type_ onClick className={category |> classNameOfCategory} title disabled> children </button>;
};
