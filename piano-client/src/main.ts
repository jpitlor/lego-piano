import { createApp } from "vue";
import "./style.css";
import App from "./App.vue";
import { library } from "@fortawesome/fontawesome-svg-core";
import {
  faComputer,
  faPauseCircle,
  faPlayCircle,
  faUser,
} from "@fortawesome/pro-regular-svg-icons";

library.add(faUser, faComputer, faPlayCircle, faPauseCircle);

createApp(App).mount("#app");
