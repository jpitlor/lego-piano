import { createApp } from "vue";
import "./style.css";
import App from "./App.vue";
import { library, config } from "@fortawesome/fontawesome-svg-core";
import {
  faComputer,
  faPauseCircle, faPencil,
  faPlayCircle,
  faUser,
} from "@fortawesome/pro-regular-svg-icons";

library.add(faUser, faComputer, faPlayCircle, faPauseCircle, faPencil);
config.styleDefault = "far";

createApp(App).mount("#app");
