<script setup lang="ts">
import { FontAwesomeIcon } from "@fortawesome/vue-fontawesome";
import { onMounted, ref } from "vue";

const songs = Object.values(
  import.meta.glob("../songs/*", { eager: true, as: "url" }),
) as string[];
const emit = defineEmits<{ change: [song: string | File] }>();
const isOpen = ref(false);
const fileInput = ref<HTMLInputElement>();

function selectSong(song: string) {
  emit("change", song);
  isOpen.value = false;
}

function selectFile() {
  if (!fileInput?.value?.files || fileInput.value.files.length < 1) {
    return;
  }

  const [file] = fileInput?.value?.files;
  emit("change", file);
  isOpen.value = false;
}

onMounted(() => {
  emit("change", songs[0]);
});
</script>

<template>
  <button>
    <font-awesome-icon icon="fa-pencil" @click="isOpen = true" />
  </button>
  <div v-if="isOpen" class="container">
    <div class="background" @click="isOpen = false" />
    <div class="modal">
      <h2>Select a Song</h2>
      <ul>
        <li v-for="song in songs" @click="selectSong(song)">
          {{ song }}
        </li>
        <li>
          <label for="file-input">
            Custom Song
            <input
              type="file"
              id="file-input"
              ref="fileInput"
              @change="selectFile()"
            />
          </label>
        </li>
      </ul>
    </div>
  </div>
</template>

<style scoped>
.container {
  position: fixed;
  inset: 0;
  display: flex;
  align-items: center;
  justify-content: center;
  padding: 25%;
}

.background {
  position: absolute;
  inset: 0;
  background: rgba(0, 0, 0, 0.6);
}

.modal {
  background: #ffffff;
  border: 3px solid #000000;
  border-radius: 15px;
  z-index: 999;
}

ul {
  list-style: none;
}

li {
  margin: 10px;
}
</style>
