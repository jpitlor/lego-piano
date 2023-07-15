import { reactive } from "vue";

export const store = reactive({
  title: "Select a song:",
  file: null as string | null,
  ws: new WebSocket("ws://localhost:8080/"),
});
