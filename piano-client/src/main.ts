import { createApp } from "vue";
import "./style.css";
import App from "./App.vue";
import { library } from "@fortawesome/fontawesome-svg-core";
import { faComputer, faUser } from "@fortawesome/pro-regular-svg-icons";

library.add(faUser, faComputer);

createApp(App).mount("#app");
